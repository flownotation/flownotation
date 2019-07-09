FROM alpine:latest
# FROM ubuntu:latest
WORKDIR /fln
COPY ./src/pycparser /fln/pycparser
# RUN apt-get update && apt-get install --no-install-recommends --no-install-suggests -y gcc python
RUN apk update && apk add build-base python2
RUN cd /fln/pycparser && python setup.py install

