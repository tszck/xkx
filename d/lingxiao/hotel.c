// Room: /d/lingxiao/hotel.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "冰雪軒");
	set("long", @LONG
這裏是凌霄城裏最大的酒樓冰雪軒，同時也是凌霄城的名跡之一。
大凡過往旅客，不管是販夫走卒，還是文人墨客，遷客騷人，都要到此
一醉。當年謝煙客獨闖凌霄城，在此狂飲十八壇烈酒之後，殺入凌霄內
城。從此，凌霄城冰雪軒的大名，便是名聞四海。
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31010);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

