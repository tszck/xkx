// /kaifeng/xiangguosi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "相國寺門");
	set("long", @LONG
大相國寺佔地五百餘畝，轄六十四個禪，律院，養僧千餘。是京城
最大的寺院和全國佛教活動中心。門前『大相國寺』的匾額乃是當今御
筆親書。大門敞開，多有行人來往。
LONG);
	set("objects", ([
		__DIR__"npc/zhike" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"jiedao",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
