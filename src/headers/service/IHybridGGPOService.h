#pragma once

namespace HybridGGPO
{
	class HybridGGPOServiceProvider;

	class IHybridGGPOService
	{
	public:
		virtual void	eject() = 0;
		virtual void	init(HybridGGPOServiceProvider* serviceProvider) = 0;
	};
}
