#!/usr/local/bin/ruby
require "spaceship"

if ARGV.size() < 1
	puts('Usage: device_manage email')
	exit
end

$username = ARGV[0]

puts("Start login ...")
Spaceship.login($username)
puts("Login complete.")

Spaceship.select_team

puts("Collecting devices ...")
$devices = Spaceship.device.all
puts(String($devices.size) + " devices collected.")

def list_all_devices()
	$devices.collect do |device|
		puts('--------------------------------')
		puts(device.name)
		puts(device.udid)
	end
end

def show_connect_device_udid()
	value = `system_profiler SPUSBDataType | sed -n '/iPhone/,/Serial/p' | grep "Serial Number:" | awk -F ": " '{print $2}'`
	puts value
	return value
end

def check_device_exist(udid)
	$devices.collect do |device|
		if udid.chomp == device.udid.chomp
			puts("device already exist.")
			return false
		end
	end
	return true
end

def add_connect_device()
	value = `system_profiler SPUSBDataType | sed -n '/iPhone/,/Serial/p' | grep "Serial Number:" | awk -F ": " '{print $2}'`
	value = value.chomp
	if value
		add_device(value)
	else
		puts('device not found.')
	end
end

def add_device(udid)
	if check_device_exist(udid)	
		print('want to add device:' + udid + '? (y or n) ')
		choice = gets.chomp
		if choice == 'y'
			print('input device name: ')
			device_name = gets.chomp
			puts('add device => name: ' + device_name + ' udid: '+ udid)
			Spaceship.device.create!(name:device_name,udid:udid)
		end
	end
end

def show_usage()
	puts("Commands:")
	puts(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
	puts("ls\t\t\tshow all devices")
	puts("conndev\t\t\tshow udid of connecting device")
	puts("addconndev\t\t\tadd connecting device udid")
	puts("adddev\t\t\tadd device udid")
	puts("q\t\t\tquit")
	puts("h\t\t\tthis doc")
	puts(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
end

while true
	print('>> ')
	a = STDIN.gets.chomp
	case a
	when 'ls'
		list_all_devices()
	when 'conndev'
		show_connect_device_udid()
	when 'addconndev'
		add_connect_device()
	when 'adddev'
		print('input udid: ')
		udid = gets
		add_device(udid)
	when 'q'
		exit
	when 'h'
		show_usage()
	end
end