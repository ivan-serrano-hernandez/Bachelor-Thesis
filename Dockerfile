FROM ros:humble 
WORKDIR /app

COPY . /app 

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



ENV TERM xterm-256color
CMD ["bash", "-l"]
