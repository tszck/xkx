// Room: /d/luoyang/huadian.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "花店");
	set("long",  @LONG
這是一家出售各種花卉的店鋪，你被怡人的花香，多采的花姿所吸
引，信步踱入店中。老闆娘能在這兵荒馬亂的年頭，保留這麼一家花店
讓人實在難以想象。店面上掛了個牌子(paizi)。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"southroad",
		"north" :  __DIR__"eastroad",
	]));
	set("item_desc",  ([
		"paizi" : "
送花服務： send <花草代號> to <玩家代號> \n",
	]));
	set("objects",  ([
		__DIR__"npc/laoban" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
