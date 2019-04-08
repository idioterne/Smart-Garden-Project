width = 13.3;
height = 30.3;
depth = 14; //module's height is only 8

hole_offset_from_top = 6.75;
diameter = 2.1;
width_cable_opening = 8.4;
height_cable_opening = 5.4;


difference()
{
    //base
    cube([width+2, height+2, depth+2], center = true);
    
    //cube difference
    translate([0,0,1])
    cube([width, height, depth], center = true);
    
    //opening for connections
    translate([0,-height/2,2])
    cube([width_cable_opening, height_cable_opening, 2], center = true);
    
    translate([0,-((height/2)+0.5),0])
    rotate([0,0,0])
    cube([width+2,1,depth+2], center = true);
    
    translate([0,-((height/2)-1),-((depth/2)-0.5)])
    cube([10,2,1], center = true);
  
}

translate([0,-(height/2-hole_offset_from_top),-(depth/2)+2])
cylinder(h = 5, r=diameter/2, $fn = 128, center = true);


//top
difference(){

    translate([0,-25,-(depth/2+0.5)])
    rotate([90,0,0])
    cube([width+2,1,depth+2], center = true);
    
    translate([0,-26,-(depth/2+0.5)])
    cube([width_cable_opening,5,depth+2], center = true);

} 


