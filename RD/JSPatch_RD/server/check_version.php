<?php

$app_ver = $_GET["app_ver"];
if (file_exists($app_ver)) {
	$patch_dir = dir($app_ver);
	$latest_patch_ver = 1;

	$patch_file = "{$app_ver}/v{$latest_patch_ver}.zip";
	if(!file_exists($patch_file))
	{
		echo ret_failed("no patch");	
	}
	else
	{
		while ( file_exists($patch_file) ) {
			$latest_patch_ver++;
			$patch_file = "{$app_ver}/v{$latest_patch_ver}.zip";
		}
		echo ret_version($latest_patch_ver - 1);
	}
}
else
{
	echo ret_failed("no app version");
}

function ret_version($ver)
{
	return json_encode(["ver" => $ver,"code" => 0]);
}

function ret_failed($msg)
{
	return json_encode(["msg" => $msg,"code" => -1]);
}