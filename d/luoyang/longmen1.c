// Room:  /d/luoyang/longmen1.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "龍門山色");
	set("long",  @LONG
這裏因伊水東西兩岸之香山和龍門山夾峙，形若門闕，故古稱“伊
闕”，隋唐以後，習稱龍門。是進出洛陽的南面雄關。伊水流經其中，
宛如一條長龍穿門而過，通稱“龍門”。白居易曾說“洛陽西郊山水之
勝，龍門首焉”，因而“龍門山色”很早被譽爲洛陽八大景之首。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"road3",
		"north"  :  __DIR__"road4",
		"west"   :  __DIR__"pingquan",
		"eastup" :  __DIR__"longmen",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -45);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
