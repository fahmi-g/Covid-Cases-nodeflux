FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y
RUN apt-get -y install g++ cmake git
RUN apt install -y build-essential

RUN git clone https://github.com/chriskohlhoff/asio.git
WORKDIR /asio/asio
RUN mv include /usr/local/

WORKDIR /
RUN git clone https://github.com/CrowCpp/Crow.git
WORKDIR /Crow
RUN mv include/* /usr/local/include/

WORKDIR /
COPY . .
RUN g++ main.cpp CustomTimeValidation.cpp
CMD ./a.out