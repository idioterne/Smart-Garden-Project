sRad = 1.55;
bRad = 3.05;
border = 2;
h = 20;
w = 19.7;
d = 5;
bW=w+(border*2);
bH=h+border;
bD=d+border;

union(){    
    difference(){
        cube([bD,bW,bH]);
            
        translate([border,border,0])
        cube([d,w,h]);
        
        translate([border+2,bW/2-2.5,bH-5])
        cube([10,5,20]);
    }
    
    translate([0,bW/2,bRad+2])
    rotate([0,90,0])
    cylinder(5,bRad,bRad,$fn=60);
    
    translate([0,border+sRad+0.5,h-sRad-0.5])
    rotate([0,90,0])
    cylinder(5,sRad,sRad,$fn=60);
    
    translate([0,w+border-sRad-0.5,h-sRad-0.5])
    rotate([0,90,0])
    cylinder(5,sRad,sRad,$fn=60);
}