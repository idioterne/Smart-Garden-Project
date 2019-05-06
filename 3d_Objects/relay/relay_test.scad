l = 45;
w = 18;
h = 10;
border = 5;

difference(){
    cube([l+border,w+border,h+border],true);
    translate([0,0,border/2])
    cube([l,w,h+border],true);
}