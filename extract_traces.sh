ID="$1"
rm -rf traces/*
docker cp "$ID":./app/traces/detections ./traces/
docker cp "$ID":./app/traces/publisher ./traces/
docker cp "$ID":./app/traces/reviewer ./traces/
docker cp "$ID":./app/traces/main_subscriber ./traces/
docker cp "$ID":./app/traces/trail_subscriber ./traces/
docker cp "$ID":./app/traces/tie_breaker ./traces/
zip -r traces.zip traces/
mv traces.zip ../




