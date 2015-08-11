TinySDNController
========================================

TinySDNController(use TSC for short) is an light event-driven SDN SAL(South Abstract Layer) controller. Most SDN controller contains three layer, communicated by RPC or REST-API, thay are north abstract layer, middleware and sourth abstract layer. TSC need route platform to supply route or path, we insert TSC into xorp.ct, so we use json-rpc to communicate. As TSC need to accept package from OVS, so we use event driven mechanism.


Step 1
========================================

First, we construct a small json-server using jsoncpp and ACE async-module.

