#include <ansi.h>

void init()
{
	add_action("do_zhu","zhu");
	add_action("do_answer","answer");
}
int do_zhu(string arg)
{
	object me,ob;
	string type ,w_name, id;
	me = this_player();
	ob = this_object();
	type = ob->query("type");
	if(!(me->query_temp("m_make")) ||
	     me->query_temp("m_make") != ob->query("type") ) return 0;

	if((me->query("weapon/make")) )
	{
		message_vision("$N一臉茫然：您已經有一把自造的武器了，還來幹什麼？難到不可手麼？\n",ob);
		return 2;
	}
	if( !arg )
		return notify_fail(ob->query("name")+"認真的説：想好名稱及代號後再對我説。\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("使用(zhu "+type+"的名字 英文代號)\n");
	if(id == "corpse" || w_name == "corpse")
		return notify_fail("非法的名字或英文代號。\n");
	if (strwidth(w_name)>75) return notify_fail("你選擇的名字太長了吧。\n");
	if (strwidth(id) > 20) return notify_fail("你選擇的英文代號太長了吧。\n");
	w_name = replace_string(w_name, "$BLK$", BLK);
	w_name = replace_string(w_name, "$RED$", RED);
	w_name = replace_string(w_name, "$GRN$", GRN);
	w_name = replace_string(w_name, "$YEL$", YEL);
	w_name = replace_string(w_name, "$BLU$", BLU);
	w_name = replace_string(w_name, "$MAG$", MAG);
	w_name = replace_string(w_name, "$CYN$", CYN);
	w_name = replace_string(w_name, "$WHT$", WHT);
	w_name = replace_string(w_name, "$HIR$", HIR);
	w_name = replace_string(w_name, "$HIG$", HIG);
	w_name = replace_string(w_name, "$HIY$", HIY);
	w_name = replace_string(w_name, "$HIB$", HIB);
	w_name = replace_string(w_name, "$HIM$", HIM);
	w_name = replace_string(w_name, "$HIC$", HIC);
	w_name = replace_string(w_name, "$HIW$", HIW);
	w_name = replace_string(w_name, "$NOR$", NOR);
	w_name = replace_string(w_name, "\\n", "");
	w_name = replace_string(w_name, "$N", "");
	w_name = replace_string(w_name, "$n", "");
	w_name = replace_string(w_name, "\"", "");
	w_name += NOR;
	message_vision("$N説道：準備要鑄叫做 "+w_name+"("+id+")"+" 的"+type+"。\n",ob);
	message_vision("$N説道：你準備好了嗎？(answer y)。\n",ob);
	me->set_temp("m_check",1);
	me->set_temp("m_w/name",w_name);
	me->set_temp("m_w/id",id);
	return 1;
}
int do_answer(string arg)
{
	object ob=this_object();
	object me=this_player();
	string type = ob->query("type");
	string w_name,id,make_time,o_name;
	object weapon;
	if (!me->query_temp("m_check")) return 0;
	me->delete_temp("m_check");
	if (arg != "y" && arg != "Y") return notify_fail(ob->query("name")+"説道：好吧，你再考慮清楚一下。\n");
// 開始生成武器
	me->delete_temp("m_make");
	me->delete_temp("get_orc");
	me->delete_temp("or");
	if(me->query_temp("shenmu") ) o_name="千年神木";
	if(me->query_temp("jinmu") )  o_name="海底金母";
	if(me->query_temp("hanzhu") ) o_name="寒絲羽竹";
	if(me->query_temp("ironstone") ) o_name="隕星鐵石";
	w_name = me->query_temp("m_w/name");
	id = me->query_temp("m_w/id");
	make_time=NATURE_D->game_time();
	message_vision("$N沉吟了一會，對$n悄聲説了幾句話。$n點了點頭。説：好吧！\n",me,ob);
	message_vision("\n$n回過身，轉向身後的一個巨大的火爐，鼓動真氣燃起了熊熊的大火。説：開始！\n",me,ob );
	message_vision(BLU "$N雙手握住一個巨大的鐵錘，猛的向爐中漸漸紅熱起來的"+o_name+"揮去！\n" NOR,me);
	message_vision(RED "只聽得棚的一聲巨響，錘頭和"+o_name+"粘在了一起。\n" NOR,me );
	message_vision(YEL "$N只覺得掌心一熱，渾身的血液似乎都沸騰了起來！\n" NOR,me);
	message_vision(HIM "一身精血膠合着汩汩的內氣，源源不斷的向爐中的"+o_name+"湧去！\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) ||
	(me->query("jing"))<(me->query("max_jing")) ||
	(me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "突然$N覺得氣血一陣翻湧，一口真氣接不上來。。。。 \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "只聽咯的一聲輕響，一柄巨"+type+"從爐中倏然躍起。化作一道青電猛的向$N的前胸刺來！！\n" NOR,me );
	message_vision("$n見狀大叫：神"+type+"初成，人血以祭！！閃開！\n",me,ob);
	message_vision("$N只覺得眼前一花，一條白影迅捷無比的擋在了$N的身前。\n",me);
	message_vision("巨"+type+"透胸穿出，$n慘號一聲，鮮血濺得你滿臉都是！\n",me,ob);
	message_vision(RED "$n腳下一個不穩，倒在了地上，已經奄奄一息了。\n" NOR,me,ob);
	message_vision("巨"+type+"又飛了起來，飛到半空，噹的一聲落回到地上。\n爐中的火滅了。一室的勁氣化於無形，一切又歸於沉寂。\n",me );

	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("weapon/make",1);		//武器製造後防止再造的標誌
	me->set("weapon/name",w_name );	//武器的名稱
	me->set("weapon/id",id);		//武器的代號
	me->set("weapon/lv",1);			//武器等級
	me->set("weapon/or",o_name);		//記錄製造原料
	me->set("weapon/value",0);		//記錄武器升級已有的點數
	me->set("weapon/type",type);
	me->set("weapon/time",make_time);
	me->set("weapon/killed",0);

	weapon = new("/d/npc/m_weapon/weapon/m_weapon",1);
	weapon->move(this_player());
	message_vision("$n摸起地上，帶着斑斑血跡還有些燙手的巨"+type+"，説：\n"+type+"。。已。。成。。，$n的任務。。。也就完成了。。。。\n",me ,ob );
	message_vision("$n艱難的説：棒。。您。。收好，我該走了。。。\n",me,ob);
	ob->die();
// 生成武器完畢
  return 1;
}
