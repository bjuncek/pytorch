#pragma once

#include <torch/nn/cloneable.h>
#include <torch/nn/options/activation.h>
#include <torch/nn/functional/activation.h>
#include <torch/nn/modules/linear.h>

#include <torch/csrc/WindowsTorchApiMacro.h>

namespace torch {
namespace nn {

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ELU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies elu over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.ELU to learn
/// about the exact behavior of this module.
class TORCH_API ELUImpl : public torch::nn::Cloneable<ELUImpl> {
 public:
  ELUImpl() : ELUImpl(ELUOptions()) {}
  explicit ELUImpl(const ELUOptions& options_);

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `ELU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  ELUOptions options;
};

TORCH_MODULE(ELU);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Hardshrink ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the hard shrinkage function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Hardshrink to learn
/// about the exact behavior of this module.
class TORCH_API HardshrinkImpl : public torch::nn::Cloneable<HardshrinkImpl> {
 public:
  HardshrinkImpl() : HardshrinkImpl(HardshrinkOptions()) {}
  explicit HardshrinkImpl(const HardshrinkOptions& options_);

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Hardshrink` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  HardshrinkOptions options;
};

TORCH_MODULE(Hardshrink);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Hardtanh ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the HardTanh function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Hardtanh to learn
/// about the exact behavior of this module.
class TORCH_API HardtanhImpl : public torch::nn::Cloneable<HardtanhImpl> {
 public:
  HardtanhImpl() : HardtanhImpl(HardtanhOptions()) {}
  explicit HardtanhImpl(const HardtanhOptions& options_);

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `Hardtanh` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  HardtanhOptions options;
};

TORCH_MODULE(Hardtanh);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LeakyReLU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the LeakyReLU function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.LeakyReLU to learn
/// about the exact behavior of this module.
class TORCH_API LeakyReLUImpl : public torch::nn::Cloneable<LeakyReLUImpl> {
 public:
  LeakyReLUImpl() : LeakyReLUImpl(LeakyReLUOptions()) {}
  explicit LeakyReLUImpl(const LeakyReLUOptions& options_);

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `LeakyReLU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  LeakyReLUOptions options;
};

TORCH_MODULE(LeakyReLU);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LogSigmoid ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the LogSigmoid function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.LogSigmoid to learn
/// about the exact behavior of this module.
class TORCH_API LogSigmoidImpl : public torch::nn::Cloneable<LogSigmoidImpl> {
 public:
  LogSigmoidImpl() {}

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `LogSigmoid` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

TORCH_MODULE(LogSigmoid);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PReLU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the PReLU function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.PReLU to learn
/// about the exact behavior of this module.
class TORCH_API PReLUImpl : public torch::nn::Cloneable<PReLUImpl> {
 public:
  explicit PReLUImpl(const PReLUOptions& options_ = {});

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `PReLU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  PReLUOptions options;

  /// The learned weight.
  Tensor weight;
};

TORCH_MODULE(PReLU);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MultiheadAttention ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the MultiheadAttention function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.MultiheadAttention
/// to learn about the exact behavior of this module.
class TORCH_API MultiheadAttentionImpl
  : public torch::nn::Cloneable<MultiheadAttentionImpl> {
 public:
  MultiheadAttentionImpl(int64_t embed_dim, int64_t num_heads)
      : MultiheadAttentionImpl(MultiheadAttentionOptions(embed_dim, num_heads)) {}
  explicit MultiheadAttentionImpl(const MultiheadAttentionOptions& options_);

  Tensor forward(const Tensor& query, const Tensor& key, const Tensor& value,
                 const c10::optional<Tensor>& key_padding_mask = c10::nullopt,
                 bool need_weights = true,
                 const c10::optional<Tensor>& attn_mask = c10::nullopt);

  void reset() override;

  /// Pretty prints the `MultiheadAttention` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  MultiheadAttentionOptions options;

 private:
  bool _qkv_same_embed_dim;
  Tensor in_proj_weight;
  Tensor in_proj_bias;
  Tensor bias_k;
  Tensor bias_v;
  Linear out_proj = nullptr;
  Tensor q_proj_weight;
  Tensor k_proj_weight;
  Tensor v_proj_weight;
};

TORCH_MODULE(MultiheadAttention);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ReLU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the ReLU function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.ReLU to learn
/// about the exact behavior of this module.
class TORCH_API ReLUImpl : public torch::nn::Cloneable<ReLUImpl> {
 public:
  explicit ReLUImpl(const ReLUOptions& options_ = {});

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `ReLU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  ReLUOptions options;
};

TORCH_MODULE(ReLU);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ReLU6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the ReLU6 function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.ReLU6 to learn
/// about the exact behavior of this module.
class TORCH_API ReLU6Impl : public torch::nn::Cloneable<ReLU6Impl> {
 public:
  explicit ReLU6Impl(const ReLU6Options& options_ = {});

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `ReLU6` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  ReLU6Options options;
};

TORCH_MODULE(ReLU6);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RReLU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the RReLU function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.RReLU to learn
/// about the exact behavior of this module.
class TORCH_API RReLUImpl : public torch::nn::Cloneable<RReLUImpl> {
 public:
  explicit RReLUImpl(const RReLUOptions& options_ = {});

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `RReLU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  RReLUOptions options;
};

TORCH_MODULE(RReLU);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CELU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies celu over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.CELU to learn
/// about the exact behavior of this module.
class TORCH_API CELUImpl : public torch::nn::Cloneable<CELUImpl> {
 public:
  explicit CELUImpl(const CELUOptions& options_ = {});

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `CELU` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  CELUOptions options;
};

TORCH_MODULE(CELU);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sigmoid ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies sigmoid over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Sigmoid to learn
/// about the exact behavior of this module.
class TORCH_API SigmoidImpl : public torch::nn::Cloneable<SigmoidImpl> {
 public:
  explicit SigmoidImpl() {};

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Sigmoid` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

TORCH_MODULE(Sigmoid);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Softplus ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies softplus over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Softplus to learn
/// about the exact behavior of this module.
class TORCH_API SoftplusImpl : public torch::nn::Cloneable<SoftplusImpl> {
 public:
  explicit SoftplusImpl(const SoftplusOptions& options_ = {});

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Softplus` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  SoftplusOptions options;
};

TORCH_MODULE(Softplus);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Softshrink ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the soft shrinkage function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Softshrink to learn
/// about the exact behavior of this module.
class TORCH_API SoftshrinkImpl : public torch::nn::Cloneable<SoftshrinkImpl> {
 public:
  explicit SoftshrinkImpl(const SoftshrinkOptions& options_ = {});

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Softshrink` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  SoftshrinkOptions options;
};

TORCH_MODULE(Softshrink);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Softsign ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies Softsign over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Softsign to learn
/// about the exact behavior of this module.
class TORCH_API SoftsignImpl : public torch::nn::Cloneable<SoftsignImpl> {
 public:
  explicit SoftsignImpl() {}

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Softsign` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

TORCH_MODULE(Softsign);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tanh ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies Tanh over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Tanh to learn
/// about the exact behavior of this module.
class TORCH_API TanhImpl : public torch::nn::Cloneable<TanhImpl> {
 public:
  explicit TanhImpl() {}

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Tanh` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

TORCH_MODULE(Tanh);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tanhshrink ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies Tanhshrink over a given input.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Tanhshrink to learn
/// about the exact behavior of this module.
class TORCH_API TanhshrinkImpl : public torch::nn::Cloneable<TanhshrinkImpl> {
 public:
  explicit TanhshrinkImpl() {}

  Tensor forward(const Tensor& input);

  void reset() override;

  /// Pretty prints the `Tanhshrink` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

TORCH_MODULE(Tanhshrink);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Threshold ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Applies the Threshold function element-wise.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.Threshold to learn
/// about the exact behavior of this module.
class TORCH_API ThresholdImpl : public torch::nn::Cloneable<ThresholdImpl> {
 public:
  ThresholdImpl(double threshold, double value)
    : ThresholdImpl(ThresholdOptions(threshold, value)) {}
  explicit ThresholdImpl(const ThresholdOptions& options_);

  Tensor forward(Tensor& input);

  void reset() override;

  /// Pretty prints the `Threshold` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;

  /// The options with which this `Module` was constructed.
  ThresholdOptions options;
};

TORCH_MODULE(Threshold);

} // namespace nn
} // namespace torch