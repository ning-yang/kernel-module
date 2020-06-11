A test linux kernel module for read/write msr.

## Build

Install tools:

```
apt-get install build-essential linux-headers-`uname -r`
```

Then run `make`.

## Test module

Install:

```
sudo insmod msr_test.ko
sudo dmesg
```

Remove:

```
sudo rmmod msr_test
