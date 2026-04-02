// /d/beijing/andao1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地會暗道");
	set("long", @LONG
這是一條黑漆漆的地道，曲曲折折地通向前方。兩邊都是土牆，隱
約可以聽到上面腳底落地的聲音。空氣中瀰漫着潮溼的泥土氣息，令人
感到十分涼爽。一個道人站在這裏，守衛着上面的兩個出口。
LONG );
	set("exits", ([
		"north"  : __DIR__"andao2",
		"south"  : __DIR__"andao3",
		"eastup" : __DIR__"neishi",
		"westup" : __DIR__"guancai2",
	]));
	set("objects", ([
		CLASS_D("yunlong") + "/xuanzhen" : 1
	]));
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("xuan", environment(me))) && 
		(dir == "east"||dir == "west") &&
		living(present("xuan", environment(me))))
	message("vision","玄真道人把門關上了。\n","/d/beijing/andao1");
	if(dir=="east")
		message("vision","一眨眼，屋裏忽然多了一個人。\n","/d/beijing/neishi");
	if(dir=="west")
		message("vision","一眨眼，屋裏忽然多了一個人。\n","/d/beijing/guancai2");
	return ::valid_leave(me, dir);
}
