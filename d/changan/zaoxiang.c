// /d/changan/zaoxiang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "棗巷");
	set  ("long",  @LONG
你走在一條幽靜的青石小巷中，巷兩邊種着一行棗樹。不料繁華的
長安城內也有如此悠然去處。一陣棗香、一絲茶意、一聲絲竹如遠處高
樓的歌聲，隱隱飄來。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"     :  __DIR__"westroad2",
		"southwest" :  __DIR__"chaguan",
		"southeast" :  __DIR__"dongyuemiao",
		"west"      :  __DIR__"beilin",
		"east"      :  __DIR__"southroad2",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
