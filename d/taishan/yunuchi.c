// Room: /d/taishan/yunuchi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "玉女池");
	set("long", @LONG
玉女池在碧霞祠西牆外，原爲池，清代砌爲井。傳宋真宗東封泰山
時，在玉女池內發現玉女石像，易以玉像，建龕奉祭，封爲“天仙玉女
碧霞元君”。從此香火大盛。
LONG );
	set("exits", ([
		"east"  : __DIR__"bixia",
		"north" : __DIR__"sibeiya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
