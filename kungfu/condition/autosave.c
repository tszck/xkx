// autosave.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	object obj, *guards;

	switch (duration)
	{
		case 1:
			message("channel:snow",HIG"【存盤】您的檔案已自動存盤。\n"NOR,me);
			me->save();
			break;
		case 4:
			if (me->query("food") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"突然$N發出一陣“咕咕”聲響，忙用雙手捂了捂肚子：“好餓哦，要不找點喫的去？”\n"NOR, me);
			break;
		case 7:
			if (me->query("water") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"$N伸伸舌頭舔了舔乾裂的嘴脣，看來要喝點什麼了。\n"NOR, me);
			break;
		default:
			if (duration == 13) duration = 0;	
			break;
	}
	if( me->query_temp("guardfor") ) obj = me->query_temp("guardfor");
	if( me->query_temp("guardto") ) obj = environment(me);
	if( me->query_temp("guardfor") || me->query_temp("guardto") )
	{
		me->add("qi", -me->query("max_qi")/10);
		me->add("jing", -me->query("max_jing")/10);
		if(me->query("qi")<200 || me->query("jing")<200)
		{
			if (me->query_temp("guardfor"))
			{
				message_vision( HIY"$N守護這麼久，實在是太累了，只好放棄了守護"+obj->name()+"的想法。\n"NOR, me);
				guards = obj->query_temp("guarded");
				guards -= ({ me });
				obj->set_temp("guarded", guards);
				me->delete_temp("guardfor");
			}
			else
			{
				message_vision( HIY"$N把守這麼久，實在是太累了，只好放棄了把守"+obj->query("short")+"的想法。\n"NOR, me);
				obj->delete("guarded/"+me->query_temp("guardto"));
				me->delete_temp("guardto");
			}
		}
		else
		{
			if(me->query("qi")<500 || me->query("jing")<300)
				message_vision("$N守了這麼久，覺得好累。\n",me);
			else message_vision("$N守了一會，腰有點酸了。\n", me);
		}
	}
  if (me->query("max_nuqi")>0 && me->query("nuqi")>0 && 
        me->query("nuqi") < me->query("max_nuqi"))
   me->add("nuqi",-5);
   if (me->query("nuqi") < 0) me->set("nuqi",0);
	me->apply_condition("autosave", duration + 1);
	return CND_CONTINUE;
}
