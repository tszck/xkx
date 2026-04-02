// /kaifeng/yushi1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "浴室");
	set("long", @LONG
每年的五月初五日，寺中都會用清水清洗那些佛像。稱爲洗佛。用
洗佛的殘水從人的頭頂澆灌而下，稱沐佛恩。雖然水很髒，但大家都搶
了來淋水。當然達官貴人是不會當衆狼狽的所以裏面闢有專門的小浴室
供他們使用。
LONG);
	set("objects", ([
		__DIR__"npc/zhangzao" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"zhongyuan",
		"west" : __DIR__"yushi2",
	]));

	setup();
	replace_program(ROOM);
}
