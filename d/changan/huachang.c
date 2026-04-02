// /d/changan/huachang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "花場");
	set  ("long",  @LONG
雖說洛陽牡丹聞名天下，但長安菊花卻也毫不遜色。這片空地滿種
“黃金甲”，黃巢在世，想必是十分喜歡的了。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"south"  :  __DIR__"eastroad1",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5020);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
