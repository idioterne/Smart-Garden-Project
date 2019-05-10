l = 45;
w = 18;
h = 10;
border = 5;

union(){
    difference(){
        cube([l+border,w+border,h+border],true);
        translate([0,0,border/2])
        cube([l,w,h+border],true);
        translate([5,0,border])
        cube([l,w,h+border],true);
    }
    translate([0,w+(border/2),0])
    difference(){
        cube([l+border,w+border,h+border],true);
        translate([0,0,border/2])
        cube([l,w,h+border],true);
        translate([5,0,border])
        cube([l,w,h+border],true);
    }
    translate([0,(w+(border/2))*2,0])
    difference(){
        cube([l+border,w+border,h+border],true);
        translate([0,0,border/2])
        cube([l,w,h+border],true);
        translate([5,0,border])
        cube([l,w,h+border],true);
    }
}