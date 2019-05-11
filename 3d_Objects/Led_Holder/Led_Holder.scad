dist = 40;
socket = 50;
h = 10;

difference(){
    cylinder(h, d=200);
    translate([sqrt(2)*dist,0,0])
    cylinder(h*2, d=socket);
    translate([-(dist-10),dist+10,0])
    cylinder(h*2, d=socket);
    translate([-(dist-10),-(dist+10),0])
    cylinder(h* 2, d=socket);

}