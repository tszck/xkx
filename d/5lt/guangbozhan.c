// Room: /d/5lt/guangbozhan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "廣播站");
	set  ("long",  @LONG
天氣好熱，蟬兒深藏在綠樹中，叫得令人生厭。你踱着方步邁進了
廣播站，發覺這兒簡直就是另外一個世界，空中不時飄來陣陣優美的旋
律，讓人耳目頓新。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
