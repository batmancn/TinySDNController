# -*- makefile -*-
#----------------------------------------------------------------------------
#   @author : batmancn
#   @description :
#       This is a temprary makefile for TSC project. You could run by 'make controller'.
#----------------------------------------------------------------------------

all : client

client : client.o
	g++ -o ./controller/client/client.o ./controller/client/JsonClient.cpp ./controller/client/Sender.h

clean :
	rm ./controller/client/client.o
