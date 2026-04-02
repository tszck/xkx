// Room: /d/lingxiao/jianyusun.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "牢房");
	set("long", @LONG
這是一間小小的牢房，是一間丈許見方的石室。地下高低不平，都
是巨石。你睜大眼睛四下察看，只見左角落裏略有微光透入，凝目看去，
是個不到一尺見方的洞穴，貓兒或可出入，卻連小狗也鑽不過去，是送
飯時用的小孔。
LONG );
	set("exits", ([
		"east" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/sun" : 1,
	])); 
	set("coor/x", -31000);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

