# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "alpine/alpine64"
  config.vm.provision "shell", inline:<<-SCRIPT
    apk update
    apk add --no-cache musl-dev bash gcc python2
    cd /vagrant/src/pycparser
    sudo python setup.py install
  SCRIPT
end

