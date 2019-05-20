topL = 128;
bottomL = 111;
h = 37;
d=1;

hull(){
    translate([h,0,0])
    cube([1,1,d],true);
    translate([h,topL,0])
    cube([1,1,d],true);
    translate([0,(topL-bottomL)/2,0])
    union(){
        cylinder(r=5, h=d,center= true);
        translate([0,bottomL,0])
        cylinder(r=5, h=d,center= true);
    }
}
