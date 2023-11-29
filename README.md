# Dummy DIP CXX client

## Build

### Compile DIP
```
git clone https://gitlab.cern.ch/awegrzyn/dip.git
cd dip; mkdir build; cd build
cmake .. -Dlog4cplus_DIR=. -DDIP_CXX_ONLY=ON
make -j install
```

### Compile CXX client
```
git clone https://github.com/awegrzyn/dip-dummy-cxx.git
cd dip-dummy-cxx; mkdir build; cd build
cmake .. -Ddip_DIR=<install_dir>
make
```

## Run
```
dip-dummy-client <dip-dns-nodes> <dip-subscription>
```
