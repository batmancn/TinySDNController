# -*- makefile -*-
#----------------------------------------------------------------------------
#   @author : batmancn
#   @description :
#       This is a temprary makefile for TSC project. You could run by 'make controller'.
#----------------------------------------------------------------------------

all : client.o

client.o : json.o ./controller/client/Sender.h
	g++ ./controller/client/JsonClient.cpp

json.o : ./jsoncpp/dist/jsoncpp.cpp ./jsoncpp/dist/json/json.h ./jsoncpp/dist/json/json-forwards.h
	g++ ./jsoncpp/dist/jsoncpp.cpp

clean :
	rm ./controller/client/client.o
