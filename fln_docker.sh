#/bin/bash

docker run --rm -v $(pwd):/data fln sh -c "cd /data && python src/fln_main.py $1"

