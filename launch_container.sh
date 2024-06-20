NAME="$1"

docker run --gpus all -it --privileged -e DISPLAY=$DISPLAY --runtime=nvidia --net=host --volume="$HOME/.Xauthority:/root/.Xauthority:rw" -v /tmp/.X11-unix:/tmp/.X11-unix "$NAME"
