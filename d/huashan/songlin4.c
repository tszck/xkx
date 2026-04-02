// Room: /d/huashan/songlin3.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	int dir1,dir2,dir3,dir4;
	dir1=random(4)+1;
	dir2=random(4)+1;
	dir3=random(4)+1;
	dir4=random(4)+1;
	while (dir1!=1 && dir2!=1 && dir3!=1 && dir4!=1)	
	{	
		dir1=random(4)+1;
		dir2=random(4)+1;
		dir3=random(4)+1;		
		dir4=random(4)+1;		
	}
	set("short", "松樹林");
	set("long", @LONG
這是一片松樹林。幾丈高的松樹密密麻麻，遮得不見天日。地上落
滿松針，有不知名的野兔偷偷逃過。四周一片寂靜。
LONG );
	set("exits", ([
		"east"  : __DIR__"songlin"+dir1,
		"west"  : __DIR__"songlin"+dir2,
		"south" : __DIR__"songlin"+dir3,
		"north" : __DIR__"songlin"+dir4,
	]));
	set("objects", ([
		__DIR__"npc/lin-pingzhi": 1,
	]));

	set("outdoors", "huashan");
	set("coor/x", -880);
	set("coor/y", 350);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
