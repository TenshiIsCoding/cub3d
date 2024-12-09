
## Trigonometry review



### Reminder of triangle side names:

![Triangle|400](attachments/triangle.png)

#### Sine formula:
$$\sin(a) = \frac{\text{opposite}}{\text{hypotenuse}}$$
#### Cosine formula:
$$\cos(a) = \frac{\text{adjacent}}{\text{hypotenuse}}$$
#### Tangent formula:
$$\tan(a) = \frac{\text{opposite}}{\text{adjacent}}$$


### So why are we using triangles?

![[attachments/example.png]]

since we'll be using Ray Casting to render we'll encounter a lot of triangles and we'll be using formulas to help us know how to render said walls.

#### An example of using the formulas {#example-formulas} 

![[attachments/example 2.png]]

In this case, the variables we have at hand (since we divided the projection plane and FOV by 2 to get a triangle) are; the angle (30°) and the size of half the projection plane size (160).

so the most suitable formula to use is the tangent formula:
$$\tan(a) = \frac{\text{opposite}}{\text{adjacent}}$$
$$\tan(30°) = \frac{\text{160}}{\text{adjacent}}$$
which then becomes:
$${\text{adjacent}} = \frac{\text{160}}{\tan(30)} = 277.29$$
so, now we have:
	* Dimension of the projection plane : **320 x 200**
	* Distance from player to projection plane: **277.29** pixels


### Pythagorean theorem

![[attachments/pth.png]]

In this example, we can use the **Pythagorean theorem** to get the distance between the point *A* and point b in *B* in a Cartesian coordinates system

in C code, this would be:

```c
double deltaX = xB - xA;
double deltaY = yB - yA;
double hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY);
```

### Angles and radians

![[attachments/Screen Shot 2023-10-18 at 3.48.21 PM 5.png|600]]

Like in the image above, we know that 1 radian is the the angle that we get when the arc length we get is equal to the radius

![[attachments/Screen Shot 2023-10-18 at 3.53.21 PM.png]]

And we can use this unit o keep traversing through the circle, but we notice that the equivalent of 180° is π and 2 π completes a full circle
#### Conversion from degrees to Radian

![[attachments/Screen Shot 2023-10-18 at 4.47.42 PM.png]]

As we can see above, we can now visualize the difference between degrees and radians.

and the formula for conversion is:
$$a_{rad} = a_{deg} * \frac{\text{π}}{\text{180}}$$
in code, that would be:

```c
double deg2rad(double degrees)
{
	return (degrees * (PI / 180.0));
}
```

and the function that would get us radians to degrees:

```c
double rad2deg(double radians)
{
	return (radians * (180.0 / PI);
}
```

Now, if we want to know how to project rays:

![[attachments/Screen Shot 2023-10-18 at 5.00.04 PM.png]]

Assuming our projection plane is **320 X 200** and we want to know the increment between each ray to complete the 60°;

* The distance between rays would be: $$\frac{\text{60°}}{320}$$
* in code that would be:
```js
const FOV_ANGLE = 60 * (Math.PI / 180); // conversion to radians
const NUM_RAYS = 320;

rayAngle += FOV_ANGLE / NUM_RAYS; // angle divided by projection plane
```

## 2D map and player movement

### 2D map

The best datatype to represent a map in our game would be an array,

![[attachments/Screen Shot 2023-10-18 at 5.51.04 PM.png]]

In this example we will define that the size of each tile to be 32.

![[attachments/Screen Shot 2023-10-20 at 11.23.21 AM.png|400]]

after rendering the map composed of 2d arrays composed of 1's and 0's

```c
game.map = {{1, 1, 1, 1},
		    {1, 0, 0, 1},
		    {1, 0, 0, 1},
		    {1, 1, 1, 1}};
```

and rendering a different square color depending on which character is in said tile, we'll now move on to character movement.

### Player movement

![[attachments/Screen Shot 2023-10-20 at 11.43.57 AM.png]]

we'll imagine our player like this, with an angle of rotation that we'll use to turn him around.

to move the player we'll make a struct with an OOP approach in C 

```c
typedef struct s_player

{

	float   xpos;

	float   ypos;

	int     radius;

	int     turn_dir = 0; // Will be -1 to turn left and +1 to turn right

	int     walk_dir = 0; // Will be -1 to walk backwards and +1 to walk forward

	float   velocity= 4.0; // Determines how many pixels per frame well walk

	float   rotation_speed = 3 * (M_PI / 180); // Determines how fast we turn

	float   player_angle = M_PI / 2; // Sets our starting angle at 90°

} t_player;
```

#### Drawing a circle

i figured if i want to display a player from a top-down perspective, i'd use a circle. and to do that we first have to go over some formulas.

* Formula to get the coordinates (cx, cy) center of a square just from its length and coordinates:
$$c_{x} = x * \frac{\text{len}}{\text{2}}$$
$$c_{y} = y * \frac{\text{len}}{\text{2}}$$
* i will then draw a square normally, then check in a condition weather the pixel that we're on is within the radius to draw or not with the Pythagorean distance formula:
$$ \sqrt{(x - cx)^2 + (y - cy)^2} $$
after that i will check weather this pixel were on is < R or not to draw it.

#### Move step

![[attachments/Screenshot from 2023-11-12 11-11-19.png||300]]

### Casting rays

![[attachments/example.png]]

![[attachments/example 2.png]]

1. Subtract (FOV/2) from the player rotation angle (player.player_angle)
2. Start at column 0
3. While (column < window_X)
	* Cast a ray
	* Trace the ray until wall intersection (map{i}{j} == '1')
	* Record the intersection(x and y) and the distance(ray length)
	* Add the angle increment to move to the next ray (rayAngle += 60/320)


#### That gives us this:
![[attachments/Screenshot from 2023-11-17 15-50-18.png]]

## Wall projection

#### The following image helps us understand the process to wall projection:
![[attachments/Screenshot from 2023-11-17 15-53-36.png]]

to get the value of the projection plane we'll use the triangle similarities formula

the following image helps visualize the similarities in triangle ratios:

![[attachments/Screenshot from 2023-11-18 17-06-20.png||700]]

If two objects have the same shape, they are called "similar". When two triangles are similar, the ratios of the lengths of their corresponding sides are equal.

#### Reminder for the triangle similarity equation: $$\frac{\text{A}}{B} = \frac{\text{C}}{D}$$
#### Translated to OUR variables in the game:$$\frac{\text{Actual wall height}}{Distance to wall} = \frac{\text{Projected wall height}}{distancetoprojection}$$

To actually get the values we need, we'll shuffle the values around

```C
Float distanceToPPLane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
Float wallHeight = (TILE_SIZE / g->rays.raydistance) * distanceToPPLane;
```

