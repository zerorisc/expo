# Local Github Runner Bringup Notes

Notes for bringing up a local github runner, so you're not relying on github actions
cloud instances/GCP to run things. Also allows for integration with Vivado directly
to hardware since it is running on a local server.

The basic setup is an Ubuntu machine with LXD, running a virtual machine. The LXD
machine has a bridged network connection so that it has full network connectivity,
and "resourced up" (10 core / 32G RAM / 300G limits).

## Bazel install

Bazel has to be installed from source because ubuntu doesn't have a suitably late version:

curl -Lo bazelisk https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
chmod +x bazelisk
sudo mv bazelisk /usr/bin/bazel

## Rust is needed

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

## uv is needed as pip alternative

curl -Ls https://astral.sh/uv/install.sh | bash
source $HOME/.local/bin/env

## java is needed for airgapped build

sudo apt install openjdk-17-jdk

## path requirements

/usr/local/bin is needed in the env


## sudo access is required by script

I think the scripts assume containerized builds. Sudo manual intervention is required
(or you have to configure the system to auto-trust the runner to be sudo)


## Docker is required

sudo apt update
sudo apt install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release

sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | \
    sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

echo \
  "deb [arch=$(dpkg --print-architecture) \
  signed-by=/etc/apt/keyrings/docker.gpg] \
  https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt update
sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin


# Fix symlinks under windows

## one time
  under Windows settings enter developer mode
  git config --global core.symlinks true

## patch up specific files already check out
git ls-files -s | grep ^120000  # finds symlink files
git read-tree --reset -u HEAD # resets the specific symlink to be correct

# Ubuntu 24

Ubuntu 24 defaults to Gcc 13. This is not compatible with the flow; if you try to build with it, it will spin
forever trying to figure out some sort of optimization or templating in the C++ code (didn't dig a bunch into
the specifics).

To work around this, install gcc 11 and make this the system default:

sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 100

# Building the verilog

Two methods.

## fusesoc directly

`OT_ROOT=/mnt/f/code/expo fusesoc --cores-root=$OT_ROOT run --target=sim --setup lowrisc:systems:top_darjeeling:0.1`

creates output files in `$OT_ROOT/build/lowrisc_systems_top_darjeeling_0.1/`

`sim-icarus` would have the .f-compatible file list in a `.scr` extensioned file
`src` is the soc source tree

## dvsim then extract

Run:

`python3 ./util/dvsim/dvsim.py ./hw/top_darjeeling/dv/top_darjeeling_rtl_export.hjson`

^^ maybe pare that down so I'm not getting such a blob of tests

creates output files in `$OT_ROOT/scratch/win-tweaks/chip_darjeeling_asic-sim-vcs/default`

`sim-vcs` is the vcs-ready files, with the .scr file as the .f equivalent
`src` contains the soc source tree

This version of the invocation seems to create 'padring' primitives which is probably closer to what we're looking for.

`python3 ./util/dvsim/dvsim.py ./hw/top_daric2/dv/top_daric2_rtl_export.hjson`
