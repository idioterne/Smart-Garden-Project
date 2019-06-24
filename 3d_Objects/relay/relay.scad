l = 45;
w = 18;
h = 10;
border = 5;

module relay(){
    difference(){
        cube([l+border,w+border,h+border],true);
        translate([0,0,border/2])
        cube([l,w,h+border],true);
        translate([border,0,border])
        cube([l,w,h+border],true);
    }
}

union(){
    relay();
    translate([0,w+(border/2),0])
    relay();
    translate([0,(w+(border/2))*2,0])
    relay();
}