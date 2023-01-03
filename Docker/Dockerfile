FROM alpine:3.14

RUN echo 'Hello World!'
COPY ./helloworld.sh /helloworld.sh
RUN chmod +x /helloworld.sh

ENTRYPOINT ["/helloworld.sh"]