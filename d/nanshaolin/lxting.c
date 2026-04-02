// Room: /d/nanshaolin/lxting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", MAG"立雪亭"NOR);
	set("long", @LONG
你沿臺階拾階而上，眼前出現一座亭子一般的殿堂。殿前橫匾上寫
着『立雪亭』三個大字。這裏又名達摩亭。殿內佛龕供奉達摩銅像和二
祖，三祖，四祖，五祖的立像。相傳神光在嵩山本院立雪亭立雪斷臂得
授達摩真傳衣缽的地方。殿內正中的蒲團上坐着一位白眉白鬚的老僧。
LONG );
	set("exits", ([
		"north"     : __DIR__"sblu-2",
		"southdown" : __DIR__"taijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dayi" : 1,
	]));
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6160);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if((!myfam || myfam["family_name"] != "南少林派" ||
		myfam["generation"] > 22 ) &&
		objectp(present("dayi dashi", environment(me))) &&
		dir == "north" ) 
	{
		return notify_fail("大痍大師伸手攔住你躬身説道：後面乃是本寺重地，非本派高輩弟子，不能擅入！\n");
	}
	return ::valid_leave(me, dir);
}

