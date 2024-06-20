ID="$1"
rm -rf traces/*
docker cp "$ID":./app/src/main/main_subscriber/instance1.py ./nodes/
docker cp "$ID":./app/src/main/trail_subscriber/instance2.py ./nodes/
docker cp "$ID":./app/src/main/pub/publisher.py ./nodes/
docker cp "$ID":./app/src/main/reviewer/reviewer.py ./nodes/
docker cp "$ID":./app/src/main/tiebreaker/instance3.py ./nodes/


zip -r nodes.zip nodes/
mv nodes.zip ../

