TinySDNController
========================================

TinySDNController(use TSC for short) is an light event-driven SDN SAL(South Abstract Layer) controller. Most SDN controller contains three layer, communicated by RPC or REST-API, thay are north abstract layer, middleware and sourth abstract layer. TSC need route platform to supply route or path, we insert TSC into xorp.ct, so we use json-rpc to communicate. As TSC need to accept package from OVS, so we use event driven mechanism.

#### Why need WebOVS?  
By now, there are several ways to operate Openvswitch as bellow. SDN controllers use these way to control Openvswitch as netwrok infrustructure.
<ul>
  <li>CLI using ovs-XXX tools.</li>
  <li>Use JSON-RPC to operate OVSDB.</li>
  <li>Use Openflow message to operate Vswitchd directly, which is used to operate flows.</li>
</ul>

REST API is a good way to process CRUD operation, which is used in controllers as web based access method. But in most case as bellow, we only want to operate Openvswitch directly.
<ul>
  <li>Openvswitch is porting on embedded platform, whose resource is limited.</li>
  <li>We only need Openvswitch and don't want to be complex in deployment.</li>
  <li>We want web interface to operate and show elements of Openvswitch visually.</li>
</ul>

#### What's the architecture?
As we want to use Openvswitch in kinds of platform and we want to create web application, the frontend and backend architecture should be simple and reliable. So it’s clever to reuse the resources on these platforms. 

As Openvswitch is coding by C/python, it’s a good way to use python web framework. Usually this feature requires fewer resources, it’s better to use Lighttpd as web server compared to Ngnix. So I decide to use Lighttpd as web server, use Fastcgi of Lighttpd and Flup as middleware, use Web.py as application framework in backend.

For frontend, there are kinds of technics. I decide to use AngularJS. And the configure files of Lighttpd are located in ./etc/lighttpd which is the same as Lighttpd.  
  
#### What’s backend architecture?  
The Backend is based on Web.py framework, the entry point is ./backend/app.py. The frontend interacts with backend through a bunch of RESTful APIs. If you are familiar with CLIs of Openvswitch, you will find that ovs-XXX tools are used for add bridges, ports, tunnels, flows. So I want to design RESTful APIs for CRUD operations of these elements, which is operate by ovs-vsctl and ovs-ofctl commands.  
  
#### What’s frontend architecture?  
The frontend of WebOVS is built on AngularJS v1.0.8. The entry point is ./frontend/js/app.js. The files are organized in accordance with AngularJS features: controllers, directives, filters and services. For WebOVS, most of works focus on controllers.js and directive.js.  

The UI of WebOVS is customized by bootstrap theme, which is implemented using AngularJS directives.
