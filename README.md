# Submission 1401
Source Code for Hedwig Prototype

## Dependencies
We use DPDK v21.11 in Hedwig software, and Vivado v2020.2 to synthesize the Hedwig hardware.

## Software
```bash
# install DPDK v21.11 library
cd software
mkdir build
cd build
cmake ..
make -j
```

## Hardware
There are three main steps to do the synthesis for the Hedwig hardware:
1. patch hardware code based on Corundum
2. patch configuration files for the AU250 board
3. get an CAM implementation, where we use a [open-source one](https://github.com/alexforencich/verilog-cam) and fix a subtle bug there

```bash
# patch hardware code
git clone https://github.com/corundum/corundum.git hw-prototype
cd hw-prototype
git checkout 56fe10f27d9b42f1ff9abe4d735b113008e4be9d
cd fpga/common/rtl
patch -i ~/hedwig/hardware/src.patch -p2
# get the CAM implementation
cd -
cp -r ~/hedwig/hardware/verilog-cam fpga/lib
# patch AU250 configs
cd fpga/mqnic/AU250/fpga_100g
patch -i ~/hedwig/hardware/config.patch -p2
# build
make all
```
