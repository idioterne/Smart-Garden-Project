topL = 128;
bottomL = 111;
h = 37;
d=1;
rad=10;

hull(){
    translate([h,0,0])
    cube([1,1,d],true);
    translate([h,topL,0])
    cube([1,1,d],true);
    translate([0,((topL-bottomL)/2)+rad/2,0])
    union(){
        cylinder(r=rad, h=d,center= true);
        translate([0,bottomL-rad,0])
        cylinder(r=rad, h=d,center= true);
    }
}
