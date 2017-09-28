#include "ouzel_lua.hpp"
#include "ouzel_scene_Actor_lua.hpp"
#include "ouzel_scene_ActorContainer_lua.hpp"
#include "ouzel_scene_Animator_lua.hpp"
#include "ouzel_audio_Audio_lua.hpp"
#include "ouzel_audio_AudioDevice_lua.hpp"
#include "ouzel_graphics_BlendState_lua.hpp"
#include "ouzel_graphics_BlendStateResource_lua.hpp"
#include "ouzel_BMFont_lua.hpp"
#include "ouzel_Box2_lua.hpp"
#include "ouzel_Box3_lua.hpp"
#include "ouzel_graphics_Buffer_lua.hpp"
#include "ouzel_graphics_BufferResource_lua.hpp"
#include "ouzel_gui_Button_lua.hpp"
#include "ouzel_Cache_lua.hpp"
#include "ouzel_scene_Camera_lua.hpp"
#include "ouzel_gui_CheckBox_lua.hpp"
#include "ouzel_Color_lua.hpp"
#include "ouzel_gui_ComboBox_lua.hpp"
#include "ouzel_scene_Component_lua.hpp"
#include "ouzel_ConvexVolume_lua.hpp"
#include "ouzel_input_Cursor_lua.hpp"
#include "ouzel_input_CursorResource_lua.hpp"
#include "ouzel_scene_Ease_lua.hpp"
#include "ouzel_gui_EditBox_lua.hpp"
#include "ouzel_Engine_lua.hpp"
#include "ouzel_EventDispatcher_lua.hpp"
#include "ouzel_EventHandler_lua.hpp"
#include "ouzel_scene_Fade_lua.hpp"
#include "ouzel_Font_lua.hpp"
#include "ouzel_input_Gamepad_lua.hpp"
#include "ouzel_graphics_ImageData_lua.hpp"
#include "ouzel_graphics_ImageDataSTB_lua.hpp"
#include "ouzel_INI_lua.hpp"
#include "ouzel_input_Input_lua.hpp"
#include "ouzel_gui_Label_lua.hpp"
#include "ouzel_scene_Layer_lua.hpp"
#include "ouzel_audio_Listener_lua.hpp"
#include "ouzel_Localization_lua.hpp"
#include "ouzel_Log_lua.hpp"
#include "ouzel_graphics_Material_lua.hpp"
#include "ouzel_Matrix3_lua.hpp"
#include "ouzel_Matrix4_lua.hpp"
#include "ouzel_gui_Menu_lua.hpp"
#include "ouzel_graphics_MeshBuffer_lua.hpp"
#include "ouzel_graphics_MeshBufferResource_lua.hpp"
#include "ouzel_scene_MeshRenderer_lua.hpp"
#include "ouzel_audio_Mixer_lua.hpp"
#include "ouzel_scene_Move_lua.hpp"
#include "ouzel_network_Network_lua.hpp"
#include "ouzel_Noncopyable_lua.hpp"
#include "ouzel_scene_Parallel_lua.hpp"
#include "ouzel_scene_ParticleSystem_lua.hpp"
#include "ouzel_Plane_lua.hpp"
#include "ouzel_Quaternion_lua.hpp"
#include "ouzel_gui_RadioButton_lua.hpp"
#include "ouzel_gui_RadioButtonGroup_lua.hpp"
#include "ouzel_Rectangle_lua.hpp"
#include "ouzel_scene_Repeat_lua.hpp"
#include "ouzel_graphics_Resource_lua.hpp"
#include "ouzel_scene_Rotate_lua.hpp"
#include "ouzel_scene_Scale_lua.hpp"
#include "ouzel_scene_Scene_lua.hpp"
#include "ouzel_scene_SceneManager_lua.hpp"
#include "ouzel_gui_ScrollBar_lua.hpp"
#include "ouzel_scene_Sequence_lua.hpp"
#include "ouzel_graphics_Shader_lua.hpp"
#include "ouzel_graphics_ShaderResource_lua.hpp"
#include "ouzel_scene_Shake_lua.hpp"
#include "ouzel_scene_ShapeRenderer_lua.hpp"
#include "ouzel_Size2_lua.hpp"
#include "ouzel_Size3_lua.hpp"
#include "ouzel_gui_SlideBar_lua.hpp"
#include "ouzel_audio_Sound_lua.hpp"
#include "ouzel_audio_SoundInput_lua.hpp"
#include "ouzel_audio_SoundOutput_lua.hpp"
#include "ouzel_scene_Sprite_lua.hpp"
#include "ouzel_scene_SpriteFrame_lua.hpp"
#include "ouzel_scene_TextRenderer_lua.hpp"
#include "ouzel_graphics_Texture_lua.hpp"
#include "ouzel_graphics_TextureResource_lua.hpp"
#include "ouzel_Timer_lua.hpp"
#include "ouzel_UpdateCallback_lua.hpp"
#include "ouzel_obf_Value_lua.hpp"
#include "ouzel_Vector2_lua.hpp"
#include "ouzel_Vector3_lua.hpp"
#include "ouzel_Vector4_lua.hpp"
#include "ouzel_graphics_VertexPC_lua.hpp"
#include "ouzel_graphics_VertexPCT_lua.hpp"
#include "ouzel_gui_Widget_lua.hpp"
#include "ouzel_Window_lua.hpp"


void ouzel_luabinding_all(kaguya::State &state)
{
	ouzel_luabinding_actor(state);
	ouzel_luabinding_actorcontainer(state);
	ouzel_luabinding_animator(state);
	ouzel_luabinding_audio(state);
	ouzel_luabinding_audiodevice(state);
	ouzel_luabinding_blendstate(state);
	ouzel_luabinding_blendstateresource(state);
	ouzel_luabinding_bmfont(state);
	ouzel_luabinding_box2(state);
	ouzel_luabinding_box3(state);
	ouzel_luabinding_buffer(state);
	ouzel_luabinding_bufferresource(state);
	ouzel_luabinding_button(state);
	ouzel_luabinding_cache(state);
	ouzel_luabinding_camera(state);
	ouzel_luabinding_checkbox(state);
	ouzel_luabinding_color(state);
	ouzel_luabinding_combobox(state);
	ouzel_luabinding_component(state);
	ouzel_luabinding_convexvolume(state);
	ouzel_luabinding_cursor(state);
	ouzel_luabinding_cursorresource(state);
	ouzel_luabinding_ease(state);
	ouzel_luabinding_editbox(state);
	ouzel_luabinding_engine(state);
	ouzel_luabinding_eventdispatcher(state);
	ouzel_luabinding_eventhandler(state);
	ouzel_luabinding_fade(state);
	ouzel_luabinding_font(state);
	ouzel_luabinding_gamepad(state);
	ouzel_luabinding_imagedata(state);
	ouzel_luabinding_imagedatastb(state);
	ouzel_luabinding_ini(state);
	ouzel_luabinding_input(state);
	ouzel_luabinding_label(state);
	ouzel_luabinding_layer(state);
	ouzel_luabinding_listener(state);
	ouzel_luabinding_localization(state);
	ouzel_luabinding_log(state);
	ouzel_luabinding_material(state);
	ouzel_luabinding_matrix3(state);
	ouzel_luabinding_matrix4(state);
	ouzel_luabinding_menu(state);
	ouzel_luabinding_meshbuffer(state);
	ouzel_luabinding_meshbufferresource(state);
	ouzel_luabinding_meshrenderer(state);
	ouzel_luabinding_mixer(state);
	ouzel_luabinding_move(state);
	ouzel_luabinding_network(state);
	ouzel_luabinding_noncopyable(state);
	ouzel_luabinding_parallel(state);
	ouzel_luabinding_particlesystem(state);
	ouzel_luabinding_plane(state);
	ouzel_luabinding_quaternion(state);
	ouzel_luabinding_radiobutton(state);
	ouzel_luabinding_radiobuttongroup(state);
	ouzel_luabinding_rectangle(state);
	ouzel_luabinding_repeat(state);
	ouzel_luabinding_resource(state);
	ouzel_luabinding_rotate(state);
	ouzel_luabinding_scale(state);
	ouzel_luabinding_scene(state);
	ouzel_luabinding_scenemanager(state);
	ouzel_luabinding_scrollbar(state);
	ouzel_luabinding_sequence(state);
	ouzel_luabinding_shader(state);
	ouzel_luabinding_shaderresource(state);
	ouzel_luabinding_shake(state);
	ouzel_luabinding_shaperenderer(state);
	ouzel_luabinding_size2(state);
	ouzel_luabinding_size3(state);
	ouzel_luabinding_slidebar(state);
	ouzel_luabinding_sound(state);
	ouzel_luabinding_soundinput(state);
	ouzel_luabinding_soundoutput(state);
	ouzel_luabinding_sprite(state);
	ouzel_luabinding_spriteframe(state);
	ouzel_luabinding_textrenderer(state);
	ouzel_luabinding_texture(state);
	ouzel_luabinding_textureresource(state);
	ouzel_luabinding_timer(state);
	ouzel_luabinding_updatecallback(state);
	ouzel_luabinding_value(state);
	ouzel_luabinding_vector2(state);
	ouzel_luabinding_vector3(state);
	ouzel_luabinding_vector4(state);
	ouzel_luabinding_vertexpc(state);
	ouzel_luabinding_vertexpct(state);
	ouzel_luabinding_widget(state);
	ouzel_luabinding_window(state);
}
