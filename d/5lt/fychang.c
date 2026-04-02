// Room: /d/5lt/fychang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "放映場");
	set  ("long",  @LONG
這裏是放映場，據說今天凌晨某部大片全球同步首映。天還未黑，
場內已經擠滿了佔座的村民。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad3",
	]));

	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
