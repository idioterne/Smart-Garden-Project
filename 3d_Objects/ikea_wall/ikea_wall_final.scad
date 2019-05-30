rad=15;
topL = 126.5;
bottomL = 124-rad;
h = 42-rad;
d=3;


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
