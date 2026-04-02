// Room: /d/5lt/tczhongxin.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "體彩中心");
	set  ("long",  @LONG
沒錯，這裏就是村裏的體彩中心。每逢週末，兌獎大廳裏都要人滿
為患。遍地的煙頭、狂熱的彩民，剛到這兒的人可能很不習慣，然而這
裏是出產百萬富翁的地方，越來越多的人加入了彩民們的隊伍。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"sroad3",
	]));

	set("coor/x", -140);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
