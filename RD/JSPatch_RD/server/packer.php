<?php 

const PRIVATE_KEY = <<<EOD
-----BEGIN RSA PRIVATE KEY-----
MIICXgIBAAKBgQCzo2Cm3ZsIjIV7d5Jyo+AZ2nOelVaMTZ+YthEt3QLWq4kM7PIF
0WvtuC4K7EdRTwElvIwCrK2jnGIEZbZ+KsS2G68MT1SWL6Jw05ogEi2uNPFYZf/7
csIFaL4Qf+HNFSq1bj3L9pSp78ICaUJ1uKh2Ni5dQY4/rQkaE8d1pE7AtQIDAQAB
AoGBALOM7FE9FPWxhsXG2TEOzTLqH0B14gDwoUHBUWB3FJw+7ghmWO4pyWfc/OBc
FFiXz/zI/WS69f+fknT0uThYRS5W2ebGI7czmMcBka7A9gofvQjWohMp8PCNyaXz
B0MQKUburclG+A6jMZ4NtJk95UBrrKfHfmqGOjKsxbYeGgjNAkEA5N+fwXNAE/E2
NfU/PQXkJhYWrlrHp8Gk7xY6BAiGCQThIlGqJhJ4s/97MXOyvCl54bFNI8xbLPRE
jrBTMc3pBwJBAMjt4J3kyS9QoFCc3In95OZUMMjtYbyMhfN3YuEsVgOJckQYdzoY
pNiCQTABKiR+Ve9pv1LTH5GXO2h1R/U7hWMCQQCMCI7Ua9GO4gzLIsyYZ5xZ+TXT
Y9O4vnBNoInKofRwXD3rI5A5Tx/u8afMb/+xxKbAAh0yg/xdGu8/Zn7ggB3NAkEA
jo017s+CbK8nDgo77SrUWxUgB21jCgIohrMM0/RAkgHRr74r2GvjiDfhR82LuJhp
H5JGytw+aWyCGXobs0CnQQJARcfh1sRpA+TSk/UpcpERb7n74ge+kzf/vGr4+G+F
HVI7XPvvno0VudHy3O8NUNLoC5WnPfPYmUgZooVRUA/fMQ==
-----END RSA PRIVATE KEY-----
EOD;

$files = "";
$zipFile = "script.zip";
$finalFile = "v1";
for ($i = 1; $i < count($argv); $i ++) {
    if ($argv[$i] == '-o') {
        $finalFile = $argv[$i + 1];
        break;
    }
    $files .= $argv[$i] . " ";
}

if (!empty($files)) {

    //compress files
    echo system("zip $zipFile $files"); 

    //get and encrypt zip file's md5
    $zipFileMD5 = md5_file($zipFile);
    $private_key = openssl_pkey_get_private(PRIVATE_KEY);
    $ret = openssl_private_encrypt($zipFileMD5, $encrypted, $private_key);

    if (!$ret || empty($encrypted)) {
        unlink($zipFile);
        echo "fail to encrypt file md5";
    }

    $md5File = "key";
    file_put_contents($md5File, $encrypted);

    //pack script zip file and md5 file to final zip file
    echo system("zip $finalFile $zipFile $md5File"); 

    unlink($md5File);
    unlink($zipFile);
}
