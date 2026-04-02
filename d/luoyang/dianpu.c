// Room: /d/luoyang/dianpu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "店鋪");
	set("long",  @LONG
這裏是一家專門售賣唐三彩的店鋪。傳説洛陽的唐三彩非常出名，
拿到京城去賣常常供不應求。經歷了多年的戰亂，店主似乎只注意生意
而不再關心當前局勢如何，但求能在這亂世之中保住這一間店鋪。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"southroad",
		"north" :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/dianzhu" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
