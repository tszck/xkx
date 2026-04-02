// Room: /d/luoyang/futusi.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "負圖寺");
	set("long",  @LONG
河圖洛書爲華夏文明之源頭。《易》曰：“河出圖，洛出書，聖人
則之。”相傳，距今七、八千年之伏羲時代，一龍馬從黃河躍出，其身
刻有“一六居下，二七居上，三八居左，四九居右”之數字，此爲河圖。
伏羲依照河圖而演繹爲八卦。據說這裏就是當年“龍馬負圖”之處。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"dukou",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
