#pragma once

#include "Core/Window.h"
#include "Core/Log.h"
#include "Renderer/GraphicsContext.h"

#include <SDL.h>

class DesktopWindow : public Window
{
public:
	DesktopWindow(const WindowProps& props);
	virtual ~DesktopWindow();

	void OnUpdate() override;

	inline unsigned int GetWidth() const override { return m_Data.Width; }
	inline unsigned int GetHeight() const override { return m_Data.Height; }

	// window attributes
	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
	void SetVSync(bool enabled) override;
	bool IsVSync() const override;

	//virtual void* GetNativeWindow() const { return m_Window; }

private:
	virtual void Init(const WindowProps& props);
	virtual void Shutdown();

private:
	SDL_Window* m_Window;
	std::unique_ptr<GraphicsContext> m_Context;

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	WindowData m_Data;
};