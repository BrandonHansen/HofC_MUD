#include <stdio.h>
#include "object.h"
#include "toggle.h"
static const char *tags0[] = { "entrance", NULL};
static const char *tags1[] = { "fountain", NULL};
static const char *tags2[] = { "trader", NULL};
static const char *tags3[] = { "field", NULL};
static const char *tags4[] = { "cave", NULL};
static const char *tags5[] = { "silver", "coin", "silver coin", NULL};
static const char *tags6[] = { "gold", "coin", "gold coin", NULL};
static const char *tags7[] = { "guard", "burly guard", NULL};
static const char *tags8[] = { "yourself", NULL};
static bool condition9(void)  { return guard->health == 0 || silver->location == guard; }
static const char *tags9[] = { "east", "entrance", NULL};
static bool condition10(void)  { return guard->health > 0 && silver->location != guard; }
static const char *tags10[] = { "east", "entrance", NULL};
static const char *tags11[] = { "west", "out", NULL};
static const char *tags12[] = { "west", "north", "south", "forest", NULL};
static const char *tags13[] = { "east", "north", "rock", NULL};
static const char *tags14[] = { "backroom", NULL};
static const char *tags15[] = { "east", "west", "south", "rock", NULL};
static const char *tags16[] = { "south", "door", "doorway", NULL};
static const char *tags17[] = { "south", "door", "doorway", NULL};
static const char *tags18[] = { "north", "door", "doorway", NULL};
static const char *tags19[] = { "north", "door", "doorway", NULL};
static const char *tags20[] = { "box", "wooden box", NULL};
static const char *tags21[] = { "box", "wooden box", NULL};
static const char *tags22[] = { "box", "wooden box", NULL};
static const char *tags23[] = { "key", "tiny key", NULL};
static const char *tags24[] = { "lamp", NULL};
static const char *tags25[] = { "lamp", NULL};

static bool alwaysTrue(void) { return true; }

OBJECT objs[] = {
	{	/* 0 = entrance */
		alwaysTrue,
		 "An entrance",
		tags0,
		NULL,
		NULL,
		NULL,
		 "A weathered stone doorway attached to the cliffside stands to your East, vines crawl across the aged rock and water trickles down the jagged precipice and forms pool at its feet. To your West is the road back to the village, spanning across a lush green field. Birds can be heard chirping in the distance.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 1 = fountain */
		alwaysTrue,
		 "A fountain is in the center of the room",
		tags1,
		NULL,
		NULL,
		NULL,
		 "The room is dimly lit with torch light, yet the air feels damp and humid. A running fountain can be seen in the center of the space; a circular pool with the statue of a goblin spews water from its mouth. Moss grows from the stonework surrounding the fountain and is interspersed around the room structure. There are wooden doors to your North and East.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 2 = trader */
		alwaysTrue,
		 "a trader",
		tags2,
		NULL,
		NULL,
		NULL,
		 "The room is small but well lit, a goblin sits at the other end of the room and looks at you curiously. On a tattered mat colored with patterns of red and violet is spread out various items, many with distinct shines and gleams. There is a wooden door to your West and a strange pattern of bricks on the wall to your South\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 3 = field */
		alwaysTrue,
		 "an open field",
		tags3,
		NULL,
		NULL,
		NULL,
		 "The field is a nice and quiet place under a clear blue sky.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 4 = cave */
		alwaysTrue,
		 "a little cave",
		tags4,
		NULL,
		NULL,
		NULL,
		 "The cave is just a cold, damp, rocky chamber.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 5 = silver */
		alwaysTrue,
		 "a silver coin",
		tags5,
		 field,
		NULL,
		NULL,
		 "The coin has an eagle on the obverse.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 6 = gold */
		alwaysTrue,
		 "a gold coin",
		tags6,
		 openBox,
		NULL,
		NULL,
		 "The shiny coin seems to be a rare and priceless artefact.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 7 = guard */
		alwaysTrue,
		 "a burly guard",
		tags7,
		 field,
		NULL,
		NULL,
		 "The guard is a really big fellow.\n",
		 "He has",
		"You can't get much closer than this.\n",
		99,
		 20,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 8 = player */
		alwaysTrue,
		 "yourself",
		tags8,
		 field,
		NULL,
		NULL,
		 "You would need a mirror to look at yourself.\n",
		 "You have",
		"You can't get much closer than this.\n",
		99,
		 20,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 9 = intoCave */
		condition9,
		 "a cave entrance to the east",
		tags9,
		 field,
		 cave,
		 cave,
		 "The entrance is just a narrow opening in a small outcrop.\n",
		"You see",
		 "You walk into the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 10 = intoCaveBlocked */
		condition10,
		 "a cave entrance to the east",
		tags10,
		 field,
		NULL,
		 cave,
		 "The entrance is just a narrow opening in a small outcrop.\n",
		"You see",
		 "The guard stops you from walking into the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 11 = exitCave */
		alwaysTrue,
		 "a way out to the west",
		tags11,
		 cave,
		 field,
		 field,
		 "Sunlight pours in through an opening in the cave's wall.\n",
		"You see",
		 "You walk out of the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 12 = wallField */
		alwaysTrue,
		 "dense forest all around",
		tags12,
		 field,
		NULL,
		NULL,
		 "The field is surrounded by trees and undergrowth.\n",
		"You see",
		 "Dense forest is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 13 = wallCave */
		alwaysTrue,
		 "solid rock all around",
		tags13,
		 cave,
		NULL,
		NULL,
		 "Carved in stone is a secret password 'abccb'.\n",
		"You see",
		 "Solid rock is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 14 = backroom */
		alwaysTrue,
		 "a backroom",
		tags14,
		NULL,
		NULL,
		NULL,
		 "The room is dusty and messy.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 15 = wallBackroom */
		alwaysTrue,
		 "solid rock all around",
		tags15,
		 backroom,
		NULL,
		NULL,
		 "Trendy wallpaper covers the rock walls.\n",
		"You see",
		 "Solid rock is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 16 = openDoorToBackroom */
		alwaysTrue,
		 "an open door to the south",
		tags16,
		NULL,
		 backroom,
		 backroom,
		 "The door is open.\n",
		"You see",
		 "You walk through the door into a backroom.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		 toggleBackdoor,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 17 = closedDoorToBackroom */
		alwaysTrue,
		 "a closed door to the south",
		tags17,
		 cave,
		NULL,
		 backroom,
		 "The door is closed.\n",
		"You see",
		 "The door is closed.\n",
		99,
		0,
		0,
		 toggleBackdoor,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 18 = openDoorToCave */
		alwaysTrue,
		 "an open door to the north",
		tags18,
		NULL,
		 cave,
		 cave,
		 "The door is open.\n",
		"You see",
		 "You walk through the door into the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		 toggleBackdoor,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 19 = closedDoorToCave */
		alwaysTrue,
		 "a closed door to the north",
		tags19,
		 backroom,
		NULL,
		 cave,
		 "The door is closed.\n",
		"You see",
		 "The door is closed.\n",
		99,
		0,
		0,
		 toggleBackdoor,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 20 = openBox */
		alwaysTrue,
		 "a wooden box",
		tags20,
		NULL,
		NULL,
		NULL,
		 "The box is open.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		 10,
		0,
		 isAlreadyOpen,
		 toggleBox,
		 isStillOpen,
		 isAlreadyOpen
	},
	{	/* 21 = closedBox */
		alwaysTrue,
		 "a wooden box",
		tags21,
		NULL,
		NULL,
		NULL,
		 "The box is closed.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		 toggleBox,
		 isAlreadyClosed,
		 toggleBoxLock,
		 isAlreadyUnlocked
	},
	{	/* 22 = lockedBox */
		alwaysTrue,
		 "a wooden box",
		tags22,
		 backroom,
		NULL,
		NULL,
		 "The box is closed.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		 isStillLocked,
		 isAlreadyClosed,
		 isAlreadyLocked,
		 toggleBoxLock
	},
	{	/* 23 = keyForBox */
		alwaysTrue,
		 "a tiny key",
		tags23,
		 cave,
		NULL,
		NULL,
		 "The key is really small and shiny.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 24 = lampOff */
		alwaysTrue,
		 "a lamp",
		tags24,
		 field,
		NULL,
		NULL,
		 "The lamp is off.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 25 = lampOn */
		alwaysTrue,
		 "a lamp",
		tags25,
		NULL,
		NULL,
		NULL,
		 "The lamp is on.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	}
};
