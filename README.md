# FlowNotation

## Installation

Prerequisites:

- Install Vagrant

Installation:

- Run `vagrant up`

## Running the tool

Connect to the VM:

- Run `vagrant ssh`

To parse a file:

- Place the file in this directory
- In the VM, `cd /vagrant`
- Run `./fln.sh -p FILENAME EXTENSION`
  - Example `./fln.sh -p test c`
