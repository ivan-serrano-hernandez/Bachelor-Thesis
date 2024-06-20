FROM nvidia/cuda:11.8.0-cudnn8-devel-ubuntu22.04
WORKDIR /app
COPY . /app


# ROS2 installation
	# locale set
RUN apt-get update

RUN apt update && apt install locales
RUN locale-gen en_US en_US.UTF-8
RUN update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
RUN export LANG=en_US.UTF-8

	# Ubuntu universal repo
RUN DEBIAN_FRONTEND=noninteractive apt install software-properties-common -y
RUN add-apt-repository universe -y

# Add the ROS 2 GPG key with apt
RUN apt update && apt install curl -y
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install ROS 2 (Humble) packages
RUN apt update
RUN apt upgrade -y
RUN DEBIAN_FRONTEND=noninteractive apt install ros-humble-desktop -y
RUN DEBIAN_FRONTEND=noninteractive apt install ros-dev-tools -y

# required dependencies
    # pip 3.9
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3 \
    python3-pip


RUN apt-get update && apt-get install ffmpeg libsm6 libxext6  -y

RUN python3 -m pip install --upgrade pip>=3.19
    # python packages
RUN python3 -m pip install -r requirements

RUN apt-get update
RUN apt-get install vim -y

RUN apt-get install linux-tools-common -y
RUN apt-get install linux-tools-generic -y
RUN apt-get install linux-tools-`uname -r` -y 


RUN rosdep init
RUN rosdep update

ENV TERM xterm-256color
CMD ["bash", "-l"]
