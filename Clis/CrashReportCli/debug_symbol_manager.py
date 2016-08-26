import shutil
import sys
import os
import datetime

dst_package_path = os.path.expanduser('~/Documents/Packages/')

def find_match_symbol_or_app(app_name):


if __name__ == '__main__':
    src_dir = sys.argv[1]
    product_name = sys.argv[2]
    package_dir = os.path.join(dst_package_path,product_name)
    if os.path.exists(package_dir) == False:
        os.mkdir(package_dir)

    print(product_name)
    src_dysm_path = os.path.join(src_dir,product_name + '.app.dSYM')
    src_app_path = os.path.join(src_dir, product_name + '.app')
    print(src_app_path)
    print(src_dysm_path)
    if os.path.exists(src_dysm_path):
        new_pack_name = datetime.datetime.now().strftime('%Y-%m-%d_%H_%M_%S') + ".app.dSYM"
        os.system('cp -r {0} {1}'.format(src_dysm_path, os.path.join(package_dir,new_pack_name)))
    elif os.path.exists(src_app_path):
        new_pack_name = datetime.datetime.now().strftime('%Y-%m-%d_%H_%M_%S') + ".app"
        print('cp -r {0} {1}'.format(src_app_path,new_pack_name))
        os.system('cp -r {0} {1}'.format(src_app_path,os.path.join(package_dir,new_pack_name)))