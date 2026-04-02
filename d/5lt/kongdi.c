//  Room:  /d/5lt/kongdi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "空地");
	set("long",  @LONG
這裏是溪邊一塊平坦的空地。空地的主人大概沒有什麼閒暇，只是
略微平整一下，種了些綠草。村裏的寵物們經常在這兒玩耍。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest"  :  __DIR__"fantexi",
		"north"      :  __DIR__"wroad4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -190);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}